void __thiscall Scaleform::GFx::MovieImpl::ResetFocusStates(Scaleform::GFx::MovieImpl *this)
{
  unsigned int *p_Size; // edi
  Scaleform::GFx::CharacterHandle *v2; // esi
  unsigned int *v3; // ebp
  Scaleform::RefCountNTSImpl **v4; // esi
  unsigned int v5; // ebx
  unsigned int v6; // [esp+8h] [ebp-8h]

  v6 = 0;
  if ( this->FocusGroupsCnt )
  {
    p_Size = &this->FocusGroups[0].TabableArray.Data.Size;
    do
    {
      v2 = (Scaleform::GFx::CharacterHandle *)p_Size[4];
      if ( v2 )
      {
        if ( --v2->RefCount <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle(v2);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2);
        }
      }
      p_Size[4] = 0;
      if ( (*((_BYTE *)p_Size + 41) & 1) != 0 )
      {
        v3 = p_Size - 1;
        if ( *p_Size )
        {
          v4 = (Scaleform::RefCountNTSImpl **)(*v3 + 4 * *p_Size - 4);
          v5 = *p_Size;
          do
          {
            if ( *v4 )
              Scaleform::RefCountNTSImpl::Release(*v4);
            --v4;
            --v5;
          }
          while ( v5 );
          if ( (v3[2] & 0xFFFFFFFE) != 0 )
          {
            if ( *v3 )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)*v3);
              *v3 = 0;
            }
            v3[2] = 0;
          }
        }
        else if ( !p_Size[1] )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)(p_Size - 1),
            (const void *)p_Size[2],
            0);
        }
        *p_Size = 0;
        *((_BYTE *)p_Size + 41) = 0;
      }
      p_Size[5] = 0;
      p_Size += 16;
      ++v6;
    }
    while ( v6 < this->FocusGroupsCnt );
  }
}
