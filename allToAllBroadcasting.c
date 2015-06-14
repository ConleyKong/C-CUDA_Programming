procedure ALL_TO_ALL_BC_RING(my_id, my_msg, p, result)
 begin
      left := (my_id - 1) mod p;
      right := (my_id + 1) mod p;
    result := my_msg;
    msg := result;
    for i := 1 to p - 1 do
 		send msg to right;
 		receive msg from left;
 	result := result ∪ msg;
 	endfor;
