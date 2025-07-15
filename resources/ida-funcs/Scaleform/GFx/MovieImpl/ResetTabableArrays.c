void __thiscall Scaleform::GFx::MovieImpl::ResetTabableArrays(Scaleform::GFx::MovieImpl *this)
{
  unsigned int *p_Size; // ebp
  unsigned int *v2; // edi
  Scaleform::RefCountNTSImpl **v3; // esi
  unsigned int v4; // ebx
  unsigned int v5; // [esp+0h] [ebp-8h]
  Scaleform::GFx::MovieImpl *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  v5 = 0;
  if ( this->FocusGroupsCnt )
  {
    p_Size = &this->FocusGroups[0].TabableArray.Data.Size;
    do
    {
      if ( (*((_BYTE *)p_Size + 41) & 1) != 0 )
      {
        v2 = p_Size - 1;
        if ( *p_Size )
        {
          v3 = (Scaleform::RefCountNTSImpl **)(*v2 + 4 * *p_Size - 4);
          v4 = *p_Size;
          do
          {
            if ( *v3 )
              Scaleform::RefCountNTSImpl::Release(*v3);
            --v3;
            --v4;
          }
          while ( v4 );
          if ( (v2[2] & 0xFFFFFFFE) != 0 )
          {
            if ( *v2 )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)*v2);
              *v2 = 0;
            }
            v2[2] = 0;
          }
        }
        else if ( !p_Size[1] )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)(p_Size - 1),
            (const void *)p_Size[2],
            0);
        }
        this = v6;
        *p_Size = 0;
        *((_BYTE *)p_Size + 41) = 0;
      }
      p_Size += 16;
      ++v5;
    }
    while ( v5 < this->FocusGroupsCnt );
  }
}
