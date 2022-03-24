#include "CComplexVector.h"
#include "CComplexVectorVert.h"
#include "CComplexVectorHori.h"
#include <sstream>
#include <string>

CComplexVectorHori operator +(CComplexVector &A, CComplexVector &B){
    if (A.Get_dim() != B.Get_dim())exit(2);
    CComplexVectorHori C(A.Get_dim(),"buffer");

    for(int i=0;i<A.Get_dim(); i++){
        C.Set_Re_Im(A.Get_Re(i)+B.Get_Re(i), A.Get_Im(i)+B.Get_Im(i),i);
    }

    return C;
}

CComplexVectorHori operator -(CComplexVector &A, CComplexVector &B){
    if (A.Get_dim() != B.Get_dim())exit(1);
    CComplexVectorHori C(A.Get_dim(), "buf");
    for(int i=0;i<A.Get_dim(); i++){
        C.Set_Re_Im(A.Get_Re(i)- B.Get_Re(i), A.Get_Im(i) - B.Get_Im(i),i);
    }
    return C;
}




