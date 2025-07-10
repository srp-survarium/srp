Scaleform::GFx::AS3::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *result; // eax
  char *v2; // eax
  char *v3; // esi
  _DWORD *v4; // edi
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // ecx
  unsigned int RefCount; // eax
  _DWORD *v8; // eax
  Scaleform::RefCountVImpl *v10; // ecx

  result = this->pFreeEntry;
  if ( result )
  {
    this->pFreeEntry = result->pNextEntry;
    result->pNextEntry = 0;
    --this->FreeEntriesCount;
  }
  else
  {
    v2 = (char *)this->pHeap->Alloc(this->pHeap, 64, 0);
    v3 = v2;
    if ( v2 )
    {
      *((_DWORD *)v2 + 2) = 0;
      *((_DWORD *)v2 + 3) = 0;
      *((_DWORD *)v2 + 4) = 0;
      *((_DWORD *)v2 + 5) = 0;
      *((_DWORD *)v2 + 6) = 0;
      v2[28] = 0;
      v2[32] = 0;
      v2[34] = 0;
      v2[35] = 0;
      v2[33] = -1;
      *((_DWORD *)v2 + 10) = 0;
      v4 = v2 + 40;
      *((_DWORD *)v2 + 11) = 0;
      *((_DWORD *)v2 + 15) = 0;
      *(_DWORD *)v2 = 0;
      *((_DWORD *)v2 + 1) = 0;
      v5 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)v2 + 2);
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      *((_DWORD *)v3 + 2) = 0;
      v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*((_DWORD *)v3 + 3);
      if ( v6 )
      {
        if ( ((unsigned __int8)v6 & 1) != 0 )
        {
          *((_DWORD *)v3 + 3) = (char *)v6 - 1;
        }
        else
        {
          RefCount = v6->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v6->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
          }
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      *((_DWORD *)v3 + 14) = 0;
      if ( (*(_BYTE *)v4 & 0x1Fu) > 9 )
      {
        if ( (*v4 & 0x200) != 0 )
        {
          v8 = (_DWORD *)*((_DWORD *)v3 + 11);
          if ( (*v8)-- == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
          *v4 &= 0xFFFFFDE0;
          *((_DWORD *)v3 + 11) = 0;
          *((_DWORD *)v3 + 12) = 0;
          *((_DWORD *)v3 + 13) = 0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)(v3 + 40));
        }
      }
      *v4 &= 0xFFFFFFE0;
      v10 = (Scaleform::RefCountVImpl *)*((_DWORD *)v3 + 15);
      if ( v10 )
        Scaleform::RefCountImpl::Release(v10);
      *((_DWORD *)v3 + 15) = 0;
      return (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)v3;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
