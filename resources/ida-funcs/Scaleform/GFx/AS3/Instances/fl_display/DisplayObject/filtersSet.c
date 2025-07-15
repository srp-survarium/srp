void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::filtersSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::Render::FilterSet *v4; // eax
  Scaleform::Render::FilterSet *v5; // eax
  Scaleform::Render::FilterSet *v6; // ebx
  Scaleform::GFx::AS3::Impl::SparseArray *v7; // eax
  const Scaleform::GFx::AS3::Value *v8; // esi
  int v9; // ecx
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::Resource *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  bool v13; // al
  unsigned int i; // [esp+10h] [ebp-8h]
  Scaleform::GFx::AS3::Impl::SparseArray *v15; // [esp+14h] [ebp-4h]

  v4 = (Scaleform::Render::FilterSet *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
  if ( v4 )
  {
    Scaleform::Render::FilterSet::FilterSet(v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( value )
  {
    v7 = (Scaleform::GFx::AS3::Impl::SparseArray *)&value[1].8;
    i = 0;
    v15 = (Scaleform::GFx::AS3::Impl::SparseArray *)&value[1].8;
    if ( value[1].pLower )
    {
      while ( 1 )
      {
        v8 = Scaleform::GFx::AS3::Impl::SparseArray::At(v7, i);
        (*(void (__thiscall **)(_DWORD, Scaleform::GFx::ASStringNode **))(**(_DWORD **)(v8->value.VS._1.VInt + 20) + 28))(
          *(_DWORD *)(v8->value.VS._1.VInt + 20),
          &value);
        if ( !strcmp(value->pData, "GlowFilter") )
        {
          v9 = *(_DWORD *)(v8->value.VS._1.VInt + 32);
          MHeap = this->pTraits.pObject->pVM->MHeap;
        }
        else
        {
          if ( strcmp(value->pData, "BevelFilter")
            && strcmp(value->pData, "DropShadowFilter")
            && strcmp(value->pData, "BlurFilter")
            && !Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&value, "ColorMatrixFilter") )
          {
            goto LABEL_17;
          }
          MHeap = this->pTraits.pObject->pVM->MHeap;
          v9 = *(_DWORD *)(v8->value.VS._1.VInt + 32);
        }
        v11 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int, Scaleform::MemoryHeap *))(*(_DWORD *)v9 + 4))(
                                            v9,
                                            MHeap);
        Scaleform::Render::FilterSet::AddFilter(v6, v11);
        if ( v11 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
LABEL_17:
        v12 = value;
        --value->RefCount;
        if ( !v12->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        if ( ++i >= v15->Length )
          break;
        v7 = v15;
      }
    }
  }
  v13 = this->pDispObj.pObject->GetCacheAsBitmap(this->pDispObj.pObject);
  Scaleform::Render::FilterSet::SetCacheAsBitmap(v6, v13);
  this->pDispObj.pObject->SetFilters(this->pDispObj.pObject, v6);
  this->pDispObj.pObject->SetAcceptAnimMoves(this->pDispObj.pObject, 0);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
}
