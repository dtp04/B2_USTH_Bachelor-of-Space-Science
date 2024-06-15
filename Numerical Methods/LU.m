function [x1,x2,x3] = LU(A,b)
    L=zeros(size(A,1));
    U=zeros(size(A,1));
    AL=A;
    U=A;
    for k=1:size(AL,1) %L
        for j=1:k-1
            L(k,j) =AL(k,j)/AL(j,j);
            AL(k,:)= AL(k,:) - (AL(k,j)/AL(j,j))*AL(j,:);
        end
    end
    for i =1:size(A,1)
        L(i,i)=1;
    end %L
    for k=2:size(U, 1) %U
        for j=1:(k-1) 
            U(k,:)= U(k,:) - (U(k,j)/U(j,j))*U(j,:);
        end
    end %U
    S=[L,b]; %L*z=b, find z
    for k=2:size(S, 1) 
        for j=1:(k-1) 
            S(k,:)= S(k,:) - (S(k,j)/S(j,j))*S(j,:);
        end
    end %L*z=b, find z
    S2=[U,S(:,size(S,2))]; %U*x=z, find x
    S2(size(S,1),:)= S2(size(S2,1),:)/S2(size(S2,1),size(S2,1));
    for i=-(size(S2,1)-1):-1 %Rows backwards
        for w=-(size(S2,1)):(i-1) %Inside the rows
            S2(-i,:)= (S2(-i,:) - S2(-i,-w)*S2(-w,:))/S2(-i,-i);
        end
    end %U*x=z, find x
    for i=1:size(S2,1)
        fprintf('x%d = %.5f\n', i,S2(i,size(S2,2)));
    end
end