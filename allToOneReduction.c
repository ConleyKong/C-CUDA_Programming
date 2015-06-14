//多对一规约
 procedure ALL_TO_ONE_REDUCE(d, my_id, m, X, sum)
begin
 for j := 0 to m - 1 do sum[j] := X[j ];
    mask := 0;
  for i := 0 to d - 1 do
		/* Select nodes whose lower i bits are 0 */
 		if (my_id AND mask) = 0 then
 		   if (my_id AND 2i ) = 0 then
 			msg_destination := my_id XOR 2i ;
 			send sum to msg_destination;
    else
 		msg_source := my_id XOR 2i ;
 		receive X from msg_source;
 		for j := 0 to m - 1 do
 		   sum[j] :=sum[j] + X[j ];
 	   endelse;
 	mask := mask XOR 2i; /*Setbiti of mask to 1 */
    endfor;
 end ALL_TO_ONE_REDUCE
