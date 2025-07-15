void __usercall Scaleform::GFx::Sprite::PropagateNoAdvanceGlobalFlag(
        Scaleform::GFx::Sprite *this@<ecx>,
        unsigned int a2@<esi>)
{
  bool v3; // bl
  int v4; // ebp
  Scaleform::GFx::InteractiveObject *v5; // esi
  unsigned int Flags; // eax
  int v7; // eax
  unsigned int Size; // [esp+8h] [ebp-4h]

  v3 = (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 8) != 0;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v4 = 0;
    Size = this->mDisplayList.DisplayObjectArray.Data.Size;
    do
    {
      v5 = LOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) >> 7 != 0
         ? (Scaleform::GFx::InteractiveObject *)this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter
         : 0;
      if ( v5 )
      {
        if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 8) != 0 || v3 )
          v5->Flags |= 8u;
        else
          v5->Flags &= ~8u;
        ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, unsigned int))v5->PropagateNoAdvanceGlobalFlag)(
          v5,
          a2);
        Flags = v5->Flags;
        LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
        a2 = Flags;
        v7 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))v5->CheckAdvanceStatus)(v5);
        if ( v7 == -1 )
        {
          v5->Flags |= (unsigned int)&loc_400000;
        }
        else if ( v7 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v5);
        }
      }
      ++v4;
      --Size;
    }
    while ( Size );
  }
}
