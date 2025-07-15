double __thiscall fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float>::InvokeStaticFunction(
        fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float> *this,
        float p1,
        float p2,
        unsigned int p3,
        unsigned int p4,
        unsigned int p5,
        float p6)
{
  double result; // st7

  result = p1;
  ((void (__cdecl *)(_DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, fastdelegate::FastDelegate6<float,float,unsigned int,unsigned int,unsigned int,float,float> *))this)(
    LODWORD(p1),
    LODWORD(p2),
    p3,
    p4,
    p5,
    LODWORD(p6),
    this);
  return result;
}
