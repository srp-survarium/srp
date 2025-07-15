void __thiscall Scaleform::GFx::AS3::MovieRoot::CheckSocketMessages(Scaleform::GFx::AS3::MovieRoot *this)
{
  unsigned int v1; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v2; // ebx
  unsigned int Size; // ebp
  int v4; // eax
  Scaleform::GFx::Resource **v5; // ebp
  unsigned int v6; // esi
  Scaleform::RefCountVImpl **v7; // edi
  int v8; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *v9; // esi
  unsigned int v10; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v11; // edi
  Scaleform::RefCountVImpl **v12; // esi
  unsigned int v13; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *Data; // ebp
  unsigned int v15; // eax
  unsigned int v16; // esi
  Scaleform::RefCountVImpl **v17; // ebx
  int v18; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v19; // ecx
  Scaleform::GFx::AS3::SocketThreadMgr **v20; // esi
  bool v21; // zf
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *v22; // eax
  Scaleform::RefCountVImpl **v23; // esi
  unsigned int v24; // edi
  unsigned int i; // [esp+10h] [ebp-14h]
  Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr> *ia; // [esp+10h] [ebp-14h]
  unsigned int v28; // [esp+14h] [ebp-10h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2,Scaleform::ArrayDefaultPolicy> socketsInUse; // [esp+18h] [ebp-Ch] BYREF

  v1 = 0;
  v2 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this;
  Size = 0;
  memset(&socketsInUse, 0, sizeof(socketsInUse));
  i = 0;
  if ( this->Sockets.Data.Size )
  {
    do
    {
      v4 = v1;
      if ( (int)v2[142].Data[v4].pObject->_pRCC > 1 )
      {
        v5 = (Scaleform::GFx::Resource **)&v2[142].Data[v4];
        v6 = socketsInUse.Data.Size + 1;
        if ( socketsInUse.Data.Size + 1 >= socketsInUse.Data.Size )
        {
          if ( v6 >= socketsInUse.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&socketsInUse,
              &socketsInUse,
              v6 + (v6 >> 2));
        }
        else
        {
          v7 = (Scaleform::RefCountVImpl **)&socketsInUse.Data.Data[socketsInUse.Data.Size - 1];
          v8 = -1;
          do
          {
            if ( *v7 )
              Scaleform::RefCountImpl::Release(*v7);
            --v7;
            --v8;
          }
          while ( v8 );
          v2 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this;
          if ( v6 < socketsInUse.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&socketsInUse,
              &socketsInUse,
              v6);
        }
        socketsInUse.Data.Size = v6;
        v9 = &socketsInUse.Data.Data[v6 - 1];
        if ( v9 )
        {
          if ( *v5 )
            Scaleform::RefCountImpl::AddRef(*v5);
          v9->pObject = (Scaleform::GFx::AS3::SocketThreadMgr *)*v5;
        }
      }
      v1 = i + 1;
      i = v1;
    }
    while ( v1 < v2[142].Size );
    Size = socketsInUse.Data.Size;
  }
  v10 = v2[142].Size;
  v11 = v2 + 142;
  if ( v10 )
  {
    v12 = (Scaleform::RefCountVImpl **)&v11->Data[v10 - 1];
    v13 = v2[142].Size;
    do
    {
      if ( *v12 )
        Scaleform::RefCountImpl::Release(*v12);
      --v12;
      --v13;
    }
    while ( v13 );
    if ( (v11->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( v11->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11->Data);
        v11->Data = 0;
      }
      v11->Policy.Capacity = 0;
    }
  }
  else if ( !v2[142].Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2 + 142,
      &v2[142],
      0);
  }
  v11->Size = 0;
  if ( Size )
  {
    Data = socketsInUse.Data.Data;
    ia = socketsInUse.Data.Data;
    v28 = socketsInUse.Data.Size;
    do
    {
      Scaleform::GFx::AS3::SocketThreadMgr::CheckEvents(Data->pObject);
      v15 = v11->Size;
      v16 = v15 + 1;
      if ( v15 + 1 >= v15 )
      {
        if ( v16 >= v11->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v11,
            v11,
            v16 + (v16 >> 2));
      }
      else
      {
        v17 = (Scaleform::RefCountVImpl **)&v11->Data[v15 - 1];
        v18 = -1;
        do
        {
          if ( *v17 )
            Scaleform::RefCountImpl::Release(*v17);
          --v17;
          --v18;
        }
        while ( v18 );
        Data = ia;
        if ( v16 < v11->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v11,
            v11,
            v16);
      }
      v19 = v11->Data;
      v11->Size = v16;
      v20 = (Scaleform::GFx::AS3::SocketThreadMgr **)&v19[v16 - 1];
      if ( v20 )
      {
        if ( Data->pObject )
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)Data->pObject);
        *v20 = Data->pObject;
      }
      ++Data;
      v21 = v28-- == 1;
      ia = Data;
    }
    while ( !v21 );
    Size = socketsInUse.Data.Size;
  }
  v22 = socketsInUse.Data.Data;
  v23 = (Scaleform::RefCountVImpl **)&socketsInUse.Data.Data[Size - 1];
  if ( Size )
  {
    v24 = Size;
    do
    {
      if ( *v23 )
        Scaleform::RefCountImpl::Release(*v23);
      --v23;
      --v24;
    }
    while ( v24 );
    v22 = socketsInUse.Data.Data;
  }
  if ( v22 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
}
