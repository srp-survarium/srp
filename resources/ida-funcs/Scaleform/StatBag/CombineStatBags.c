void __thiscall Scaleform::StatBag::CombineStatBags(
        Scaleform::StatBag *this,
        const Scaleform::StatBag *other,
        bool (__thiscall *combineFunc)(Scaleform::StatBag *this, unsigned int, Scaleform::Stat *))
{
  int v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // ebp
  int i; // esi
  unsigned __int16 v8; // ax
  unsigned __int16 *IdPageTable; // [esp+18h] [ebp+4h]

  v4 = 0;
  IdPageTable = other->IdPageTable;
  do
  {
    v5 = *IdPageTable;
    if ( v5 != 0xFFFF )
    {
      v6 = &other->pMem[8 * v5];
      for ( i = 0; i < 16; ++i )
      {
        v8 = *(_WORD *)&v6[2 * i];
        if ( v8 != 0xFFFF )
          combineFunc(this, i | (16 * v4), (Scaleform::Stat *)&other->pMem[8 * v8]);
      }
    }
    ++IdPageTable;
    ++v4;
  }
  while ( v4 < 256 );
}
