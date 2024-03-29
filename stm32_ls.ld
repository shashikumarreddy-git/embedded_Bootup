ENTRY(Reset_handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH=1024K		//code memory
	//SRAM1(rwx):ORIGIN =0x20000000,LENGTH=116K
	//SRAM2(rwx):ORIGIN=0x20000000+116K-4,LENGTH=16K
	SRAM(rwx):ORIGIN=0x20000000,LENGTH=128K			//data memory
}
  

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.text.*)		//all such sections can be merged into one text section
		*(.init)
		*(.fini)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		_etext = .;
	}>FLASH				//not relocatable

	_la_data = LOADADDR(.data);		//this will return the load addr of	data section
	
	.data :			//this is for initilised data
	{
		_sdata = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = .;
	}> SRAM AT> FLASH	// relocatable
	
	.bss :			//this is for uninitilised data
	{
		_sbss = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}>SRAM
}