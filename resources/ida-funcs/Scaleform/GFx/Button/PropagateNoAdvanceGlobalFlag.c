void __usercall Scaleform::GFx::Button::PropagateNoAdvanceGlobalFlag(
        Scaleform::GFx::Button *this@<ecx>,
        unsigned int a2@<edi>)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  bool v4; // cl
  unsigned int *p_Size; // ebp
  unsigned int i; // edi
  int v7; // eax
  Scaleform::GFx::InteractiveObject *v8; // esi
  unsigned int Flags; // eax
  int v10; // eax
  bool actualValue; // [esp+7h] [ebp-5h]
  int v13; // [esp+8h] [ebp-4h]

  pASRoot = this->pASRoot;
  v4 = (this->Scaleform::GFx::InteractiveObject::Flags & 8) != 0;
  actualValue = v4;
  if ( pASRoot->pMovieImpl )
  {
    p_Size = &this->States[0].Characters.Data.Size;
    v13 = 4;
    do
    {
      for ( i = 0; i < *p_Size; ++i )
      {
        v7 = *(_DWORD *)(*(p_Size - 1) + 8 * i);
        if ( v7 )
        {
          v8 = *(_BYTE *)(v7 + 62) >> 7 != 0 ? (Scaleform::GFx::InteractiveObject *)v7 : 0;
          if ( v8 )
          {
            if ( (this->Scaleform::GFx::InteractiveObject::Flags & 8) != 0 || v4 )
              v8->Flags |= 8u;
            else
              v8->Flags &= ~8u;
            ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, unsigned int))v8->PropagateNoAdvanceGlobalFlag)(
              v8,
              a2);
            Flags = v8->Flags;
            LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
            a2 = Flags;
            v10 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))v8->CheckAdvanceStatus)(v8);
            if ( v10 == -1 )
            {
              v8->Flags |= (unsigned int)&loc_400000;
            }
            else if ( v10 == 1 )
            {
              Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
            }
          }
        }
        v4 = actualValue;
      }
      p_Size += 4;
      --v13;
    }
    while ( v13 );
  }
}
