		;�xֵ,������
		mov		r0, #0x20000
		mov		r1, #1
		mov		r2, #2
		mov		r3, #3
		
		;LDMָ��:load	multiple registr
		;LDM{addr_mode}{cond}	Rn{!}, reglist{^}
		;STMָ��:store	multiple registr
		;STM{addr_mode}{cond}	Rn{!}, reglist{^}
		;addr_mode:	IA,IB,DA,DB
		;;IA:	increment after store
		;;IB:	increment before store
		;;DA:	decrement after store
		;;DB:	decrement before store
		
		;uint32_t	*p;
		;p		= (uint32_t*)(R0)
		;*p++	= R1
		;*p++	= R2
		;*p		= R3
		;;IA:	increment after store ���ȴ惦��ƫ��(��)ָ�
		;;�惦�r,�͘�̖�ļĴ��������͵�ַ
		
		stmia	r0, {r1-r3}
		
		;uint32_t	*p;
		;p		= (uint32_t*)(R0)
		;*(--p)	= R3
		;*(--p)	= R2
		;*(--p)	= R1
		;;DB:	decrement before store ����ƫ��(�p)ָ��ٴ惦
		;;�惦�r,�͘�̖�ļĴ��������͵�ַ
		stmdb	r0, {r1-r3}
		
		;��������ɷN	stmda stmibҲ����Ƶġ�
		
		
		
