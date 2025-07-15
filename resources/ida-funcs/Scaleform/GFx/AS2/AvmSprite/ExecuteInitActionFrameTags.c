void __thiscall Scaleform::GFx::AS2::AvmSprite::ExecuteInitActionFrameTags(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frame)
{
  Scaleform::RefCountNTSImpl *Capacity; // ebp
  unsigned int v4; // esi
  unsigned int v5; // ecx
  int v6; // [esp+8h] [ebp-8h] BYREF
  unsigned int v7; // [esp+Ch] [ebp-4h]

  if ( !*(_BYTE *)(frame + *(_DWORD *)&this->ASEnvironment.FuncCallNestingLevel) )
  {
    Capacity = (Scaleform::RefCountNTSImpl *)this[-1].InitActionsExecuted.Data.Policy.Capacity;
    v4 = 0;
    if ( Capacity )
      ++Capacity->RefCount;
    v5 = this[-1].InitActionsExecuted.Data.Policy.Capacity;
    v6 = 0;
    v7 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int *, unsigned int))(**(_DWORD **)(v5 + 152) + 48))(
           *(_DWORD *)(v5 + 152),
           &v6,
           frame)
      && v7 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(v6 + 4 * v4) + 4))(
          *(_DWORD *)(v6 + 4 * v4),
          this[-1].InitActionsExecuted.Data.Policy.Capacity);
        ++v4;
      }
      while ( v4 < v7 );
      *(_BYTE *)(frame + *(_DWORD *)&this->ASEnvironment.FuncCallNestingLevel) = 1;
    }
    if ( Capacity )
      Scaleform::RefCountNTSImpl::Release(Capacity);
  }
}
