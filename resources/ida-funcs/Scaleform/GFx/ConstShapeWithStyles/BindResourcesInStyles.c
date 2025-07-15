void __thiscall Scaleform::GFx::ConstShapeWithStyles::BindResourcesInStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::GFx::ResourceBinding *resourceBinding)
{
  Scaleform::GFx::ConstShapeWithStyles *v2; // edi
  unsigned __int8 *Styles; // eax
  unsigned int v4; // ebp
  Scaleform::RefCountVImpl **v5; // ebx
  volatile unsigned int RefCount; // eax
  Scaleform::GFx::ResourceBindData *v7; // esi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource_vtbl *v9; // edi
  _DWORD *v10; // esi
  unsigned int v11; // ebp
  unsigned __int8 *v12; // eax
  Scaleform::RefCountVImpl **v13; // ebx
  volatile unsigned int v14; // eax
  Scaleform::GFx::ResourceBindData *v15; // esi
  Scaleform::GFx::Resource *v16; // ecx
  Scaleform::GFx::Resource_vtbl *v17; // edi
  _DWORD *v18; // esi
  unsigned __int8 *v20; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::ResourceBindData pdata; // [esp+18h] [ebp-8h] BYREF

  v2 = this;
  Styles = this->Styles;
  v4 = 0;
  v20 = Styles;
  pdata.pResource.pObject = 0;
  pdata.pBinding = 0;
  if ( this->FillStylesNum )
  {
    v5 = (Scaleform::RefCountVImpl **)(Styles + 4);
    do
    {
      if ( *v5 )
      {
        RefCount = (*v5)[6].RefCount;
        if ( RefCount != -1 )
        {
          if ( resourceBinding->Frozen && RefCount < resourceBinding->ResourceCount )
          {
            v7 = &resourceBinding->pResources[RefCount];
            if ( v7->pResource.pObject )
              Scaleform::RefCountImpl::AddRef(v7->pResource.pObject);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
            pObject = v7->pResource.pObject;
            pdata = *v7;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(resourceBinding, &pdata, (*v5)[6].RefCount);
            pObject = pdata.pResource.pObject;
          }
          if ( pObject && (pObject->GetResourceTypeCode(pObject) & 0xFF00) == 0x100 )
          {
            v9 = pdata.pResource.pObject[1].__vftable;
            v10 = &(*v5)[1].__vftable;
            if ( v9 )
              (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v9->~Scaleform::GFx::Resource + 1))(v9);
            if ( *v10 )
              (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 8))(*v10);
            *v10 = v9;
            v2 = this;
            (*v5)[6].RefCount = -1;
          }
          else
          {
            if ( *v5 )
              Scaleform::RefCountImpl::Release(*v5);
            *v5 = 0;
            *(v5 - 1) = (Scaleform::RefCountVImpl *)-5776071;
          }
        }
      }
      ++v4;
      v5 += 2;
    }
    while ( v4 < v2->FillStylesNum );
    Styles = v20;
  }
  v11 = 0;
  v12 = &Styles[8 * v2->FillStylesNum];
  if ( v2->StrokeStylesNum )
  {
    v13 = (Scaleform::RefCountVImpl **)(v12 + 20);
    do
    {
      if ( *v13 )
      {
        v14 = (*v13)[6].RefCount;
        if ( v14 != -1 )
        {
          if ( resourceBinding->Frozen && v14 < resourceBinding->ResourceCount )
          {
            v15 = &resourceBinding->pResources[v14];
            if ( v15->pResource.pObject )
              Scaleform::RefCountImpl::AddRef(v15->pResource.pObject);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
            v16 = v15->pResource.pObject;
            pdata = *v15;
          }
          else
          {
            Scaleform::GFx::ResourceBinding::GetResourceData_Locked(resourceBinding, &pdata, v14);
            v16 = pdata.pResource.pObject;
          }
          if ( v16 && (v16->GetResourceTypeCode(v16) & 0xFF00) == 0x100 )
          {
            v17 = pdata.pResource.pObject[1].__vftable;
            v18 = &(*v13)[1].__vftable;
            if ( v17 )
              (*((void (__thiscall **)(Scaleform::GFx::Resource_vtbl *))v17->~Scaleform::GFx::Resource + 1))(v17);
            if ( *v18 )
              (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v18 + 8))(*v18);
            *v18 = v17;
            v2 = this;
            (*v13)[6].RefCount = -1;
          }
          else
          {
            if ( *v13 )
              Scaleform::RefCountImpl::Release(*v13);
            *v13 = 0;
            *(v13 - 1) = (Scaleform::RefCountVImpl *)-5776071;
          }
        }
      }
      ++v11;
      v13 += 7;
    }
    while ( v11 < v2->StrokeStylesNum );
  }
  if ( pdata.pResource.pObject )
    Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
}
