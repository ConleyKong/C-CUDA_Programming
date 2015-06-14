//在一个d维p节点的超立方体的节点0上进行消息X的一对多广播
//其中 d=log p
//and和xor分别为按位逻辑与和按位逻辑异或操作
procedure ONE_TO_ALL_BC(d,my_id,X)
begin
	mask := 2^d-1;
	for i := d-1 downto 0 do
		mask := mask XOR 2^i;
		if(my_id AND 2^i) = 0 then
			if(my_id AND 2^i)=0 then
				msg_destination := my_id XOR 2^i;
				send X to msg_destination;
			else
				msg_source := my_id XOR 2^i;
				receive X from msg_source;
			endelse;
		endif;
	endfor;
end ONE_TO_ALL_BC
