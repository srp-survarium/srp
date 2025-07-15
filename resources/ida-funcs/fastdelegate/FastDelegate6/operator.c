double __userpurge fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float>::operator()@<st0>(
        fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float> *this@<ecx>,
        int a2@<eax>,
        float p1,
        float p2,
        unsigned int p3,
        unsigned int p4,
        unsigned int p5,
        float p6)
{
  double result; // st7

  result = p1;
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD))(a2 + 4))(
    *(_DWORD *)a2,
    LODWORD(p1),
    LODWORD(p2),
    p3,
    p4,
    p5,
    LODWORD(p6),
    *(_DWORD *)(a2 + 4));
  return result;
}
