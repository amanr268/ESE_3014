clc;
disp('Please enter the value of p'); 
p=input(':');
disp('Please enter the value of p'); 
q=input(':');
 
if (isprime(p)==1 & isprime(q)==1)    

    n=p*q;
    fprintf('\nn = p*q = %d',n);
    phi=(p-1)*(q-1);
    fprintf('\nphi(%d)= (p-1)*(q-1) = (%d-1)*(%d-1) = %d',n,p,q,phi);
 
    Prime_check=0;
    Greatest_common_divisor=0;
    while(Greatest_common_divisor~=1 | Prime_check==0)
        
         e=randi([2,n],1,1);
         Prime_check=isprime(e);
         Greatest_common_divisor=gcd(e,phi);
      
    end
 
    mod_check=0;
    d=0;
 
    while(mod_check~=1);
      
         d=d+1;
         mod_check=mod(d*e,phi);
      
    end
 
    fprintf('\nd = %d',d);
    fprintf('\nPublic key is');% (%d,%d)',e,n);
    cprintf('blue', ' (%d,%d)',e,n);
    fprintf('\nPrivate key is');% (%d,%d)',d,n);
    cprintf('blue', ' (%d,%d)\n',d,n);

else

    cprintf('_red', '\nERROR 404:');fprintf(' p or q is not a prime number\n') ;

end