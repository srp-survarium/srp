void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::filtersGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  const Scaleform::Render::FilterSet *v4; // eax
  const Scaleform::Render::FilterSet *v5; // edi
  unsigned int v6; // ebp
  _DWORD *v7; // esi
  const char *v8; // eax
  Scaleform::GFx::Resource *v9; // eax
  Scaleform::RefCountVImpl *v10; // esi
  Scaleform::RefCountVImpl **p_FilterData; // edi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *v14; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int v16; // eax
  Scaleform::GFx::AS3::CheckResult v17; // [esp+Fh] [ebp-31h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> as3filter; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> array; // [esp+14h] [ebp-2Ch] BYREF
  const Scaleform::Render::FilterSet *filters; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // [esp+1Ch] [ebp-24h]
  Scaleform::GFx::AS3::Value v; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v23; // [esp+30h] [ebp-10h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v21 = this;
  Scaleform::GFx::AS3::VM::MakeArray(pVM, &array);
  v4 = this->pDispObj.pObject->GetFilters(this->pDispObj.pObject);
  v5 = v4;
  filters = v4;
  if ( v4 && v4->Filters.Data.Size )
  {
    v6 = 0;
    do
    {
      v7 = &v5->Filters.Data.Data[v6].pObject->__vftable;
      as3filter.pObject = 0;
      switch ( v7[2] )
      {
        case 0:
          v8 = "flash.filters.BlurFilter";
          goto LABEL_10;
        case 1:
          v8 = "flash.filters.DropShadowFilter";
          goto LABEL_10;
        case 2:
          v8 = "flash.filters.GlowFilter";
          goto LABEL_10;
        case 3:
          v8 = "flash.filters.BevelFilter";
          goto LABEL_10;
        case 8:
          v8 = "flash.filters.ColorMatrixFilter";
LABEL_10:
          Scaleform::GFx::AS3::VM::constructBuiltinObject(
            v21->pTraits.pObject->pVM,
            &v17,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&as3filter,
            v8,
            0,
            0);
          if ( v17.Result )
          {
            v9 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*v7 + 4))(v7, 0);
            v10 = (Scaleform::RefCountVImpl *)v9;
            p_FilterData = (Scaleform::RefCountVImpl **)&as3filter.pObject->FilterData;
            if ( v9 )
              Scaleform::RefCountImpl::AddRef(v9);
            if ( *p_FilterData )
              Scaleform::RefCountImpl::Release(*p_FilterData);
            *p_FilterData = v10;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0;
            Scaleform::GFx::AS3::Value::AssignUnsafe(&v, as3filter.pObject);
            Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&array.pV->SA, &v);
            if ( (v.Flags & 0x1F) > 9 )
            {
              if ( (v.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
            }
            if ( v10 )
              Scaleform::RefCountImpl::Release(v10);
            v5 = filters;
          }
          break;
        default:
          Scaleform::GFx::AS3::Value::Value(&v23, 0);
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&array.pV->SA, &v23);
          if ( (v23.Flags & 0x1F) > 9 )
          {
            if ( (v23.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v23);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v23);
          }
          break;
      }
      if ( as3filter.pObject )
      {
        if ( ((int)as3filter.pObject & 1) != 0 )
        {
          --as3filter.pObject;
        }
        else
        {
          RefCount = as3filter.pObject->RefCount;
          pObject = as3filter.pObject;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            as3filter.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      ++v6;
    }
    while ( v6 < v5->Filters.Data.Size );
  }
  v14 = result->pObject;
  pV = array.pV;
  if ( array.pV != result->pObject )
  {
    if ( v14 )
    {
      if ( ((unsigned __int8)v14 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v14 - 1);
        result->pObject = pV;
        return;
      }
      v16 = v14->RefCount;
      if ( (v16 & 0x3FFFFF) != 0 )
      {
        v14->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
    result->pObject = pV;
  }
}
