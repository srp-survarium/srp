void __thiscall Scaleform::GFx::MovieImpl::AddMovieDefToKillList(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDefImpl *md)
{
  Scaleform::GFx::MovieDefImpl *v2; // ebx
  unsigned int Size; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::MovieImpl::MDKillListEntry *Data; // edi
  Scaleform::GFx::MovieDefImpl **p_pObject; // edx
  unsigned int v8; // eax
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *p_MovieDefKillList; // edi
  unsigned int v10; // esi
  Scaleform::GFx::Resource **v11; // ebx
  int v12; // ebp
  int v13; // eax
  Scaleform::GFx::MovieImpl::MDKillListEntry *v14; // ecx
  Scaleform::GFx::MovieImpl::MDKillListEntry *v15; // esi
  int e; // [esp+8h] [ebp-10h]
  int e_4; // [esp+Ch] [ebp-Ch]

  v2 = md;
  if ( md )
  {
    Size = this->MovieDefKillList.Data.Size;
    v5 = 0;
    if ( Size )
    {
      Data = this->MovieDefKillList.Data.Data;
      p_pObject = &Data->pMovieDef.pObject;
      while ( *p_pObject != md )
      {
        ++v5;
        p_pObject += 4;
        if ( v5 >= Size )
          goto LABEL_6;
      }
      v13 = v5;
      LODWORD(Data[v13].KillFrameId) = this->RenderContext.SnapshotFrameIds[0];
      HIDWORD(Data[v13].KillFrameId) = HIDWORD(this->RenderContext.SnapshotFrameIds[0]);
    }
    else
    {
LABEL_6:
      e_4 = HIDWORD(this->RenderContext.SnapshotFrameIds[0]);
      e = this->RenderContext.SnapshotFrameIds[0];
      Scaleform::RefCountImpl::AddRef(md);
      v8 = this->MovieDefKillList.Data.Size;
      p_MovieDefKillList = &this->MovieDefKillList;
      v10 = v8 + 1;
      if ( v8 + 1 >= v8 )
      {
        if ( v10 >= p_MovieDefKillList->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_MovieDefKillList->Data,
            p_MovieDefKillList,
            v10 + (v10 >> 2));
      }
      else
      {
        v11 = &p_MovieDefKillList->Data.Data[v8 - 1].pMovieDef.pObject;
        v12 = -1;
        do
        {
          if ( *v11 )
            Scaleform::GFx::Resource::Release(*v11);
          v11 -= 4;
          --v12;
        }
        while ( v12 );
        v2 = md;
        if ( v10 < p_MovieDefKillList->Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_MovieDefKillList->Data,
            p_MovieDefKillList,
            v10);
      }
      v14 = p_MovieDefKillList->Data.Data;
      p_MovieDefKillList->Data.Size = v10;
      v15 = &v14[v10 - 1];
      if ( v15 )
      {
        LODWORD(v15->KillFrameId) = e;
        HIDWORD(v15->KillFrameId) = e_4;
        Scaleform::RefCountImpl::AddRef(v2);
        v15->pMovieDef.pObject = v2;
      }
      Scaleform::GFx::Resource::Release(v2);
    }
  }
}
