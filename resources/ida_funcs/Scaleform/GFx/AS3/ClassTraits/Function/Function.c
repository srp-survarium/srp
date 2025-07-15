void __thiscall Scaleform::GFx::AS3::ClassTraits::Function::Function(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::MemoryHeap *MHeap; // edi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v6; // esi
  Scaleform::GFx::AS3::Class *v7; // eax
  Scaleform::GFx::AS3::Class *v8; // edi
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v11; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v13; // esi
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v16; // esi
  Scaleform::GFx::AS3::Class *v17; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *p_pConstructor; // esi
  unsigned int v19; // eax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v20; // eax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v21; // esi
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v22; // ecx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v24; // esi
  Scaleform::GFx::AS3::Class *v25; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *v26; // esi
  unsigned int v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v28; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v29; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v30; // esi
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v31; // ecx
  unsigned int v32; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v33; // esi
  Scaleform::GFx::AS3::Class *v34; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *v35; // esi
  unsigned int v36; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v37; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v38; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v39; // esi
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v40; // ecx
  unsigned int v41; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v42; // esi
  Scaleform::GFx::AS3::Class *v43; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *v44; // esi
  unsigned int v45; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, ci);
  this->__vftable = (Scaleform::GFx::AS3::ClassTraits::Function_vtbl *)&Scaleform::GFx::AS3::ClassTraits::Function::`vftable';
  this->ThunkTraits.pObject = 0;
  this->ThunkFunctionTraits.pObject = 0;
  this->MethodIndTraits.pObject = 0;
  this->VTableTraits.pObject = 0;
  this->TraitsType = Traits_Function;
  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->Alloc(MHeap, 132u, 0);
  v6.pV = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v5, vm, ci);
    v6.pV->__vftable = (Scaleform::GFx::AS3::InstanceTraits::Traits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable';
    v6.pV[1].RefCount = 0;
    v6.pV[1].FirstOwnSlotNum = 0;
    v6.pV[1].Parent = 0;
    v6.pV->TraitsType = Traits_Function;
    v6.pV->MemSize = 72;
    Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots((Scaleform::GFx::AS3::InstanceTraits::Function *)v6.pV);
  }
  else
  {
    v6.pV = 0;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v6);
  v7 = (Scaleform::GFx::AS3::Class *)MHeap->Alloc(MHeap, 40u, 0);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v8->__vftable = (Scaleform::GFx::AS3::Class_vtbl *)&Scaleform::GFx::AS3::Classes::Function::`vftable';
  }
  else
  {
    v8 = 0;
  }
  pObject = v6.pV->pConstructor.pObject;
  if ( v8 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v6.pV->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    v6.pV->pConstructor.pObject = v8;
  }
  v11 = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)vm->MHeap->Alloc(vm->MHeap, 120, 0);
  if ( v11 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(v11, vm);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = this->ThunkTraits.pObject;
  if ( v13 != v14 )
  {
    if ( v14 )
    {
      if ( ((unsigned __int8)v14 & 1) != 0 )
      {
        this->ThunkTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)((char *)v14 - 1);
      }
      else
      {
        v15 = v14->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v15) != 0 )
        {
          v14->RefCount = v15 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
        }
      }
    }
    this->ThunkTraits.pObject = v13;
  }
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v16 = this->ThunkTraits.pObject;
  v17 = v16->pConstructor.pObject;
  p_pConstructor = &v16->pConstructor;
  if ( v8 != v17 )
  {
    if ( v17 )
    {
      if ( ((unsigned __int8)v17 & 1) != 0 )
      {
        p_pConstructor->pObject = (Scaleform::GFx::AS3::Class *)((char *)v17 - 1);
      }
      else
      {
        v19 = v17->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v19) != 0 )
        {
          v17->RefCount = v19 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
        }
      }
    }
    p_pConstructor->pObject = v8;
  }
  v20 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)vm->MHeap->Alloc(vm->MHeap, 120, 0);
  v21 = v20;
  if ( v20 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v20, vm, &Scaleform::GFx::AS3::fl::FunctionCIThunk);
    v21->__vftable = (Scaleform::GFx::AS3::InstanceTraits::CTraits_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
    v21->TraitsType = Traits_Function;
    v21->MemSize = 40;
    Scaleform::GFx::AS3::Traits::Add2VT(
      v21,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::f);
  }
  else
  {
    v21 = 0;
  }
  v22 = this->ThunkFunctionTraits.pObject;
  if ( v21 != v22 )
  {
    if ( v22 )
    {
      if ( ((unsigned __int8)v22 & 1) != 0 )
      {
        this->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)((char *)v22 - 1);
      }
      else
      {
        v23 = v22->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v23) != 0 )
        {
          v22->RefCount = v23 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
        }
      }
    }
    this->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)v21;
  }
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v24 = this->ThunkFunctionTraits.pObject;
  v25 = v24->pConstructor.pObject;
  v26 = &v24->pConstructor;
  if ( v8 != v25 )
  {
    if ( v25 )
    {
      if ( ((unsigned __int8)v25 & 1) != 0 )
      {
        v26->pObject = (Scaleform::GFx::AS3::Class *)((char *)v25 - 1);
      }
      else
      {
        v27 = v25->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v27) != 0 )
        {
          v25->RefCount = v27 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
        }
      }
    }
    v26->pObject = v8;
  }
  v28 = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)vm->MHeap->Alloc(vm->MHeap, 120, 0);
  if ( v28 )
  {
    Scaleform::GFx::AS3::InstanceTraits::MethodInd::MethodInd(v28, vm);
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  v31 = this->MethodIndTraits.pObject;
  if ( v30 != v31 )
  {
    if ( v31 )
    {
      if ( ((unsigned __int8)v31 & 1) != 0 )
      {
        this->MethodIndTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)((char *)v31 - 1);
      }
      else
      {
        v32 = v31->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v32) != 0 )
        {
          v31->RefCount = v32 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
        }
      }
    }
    this->MethodIndTraits.pObject = v30;
  }
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v33 = this->MethodIndTraits.pObject;
  v34 = v33->pConstructor.pObject;
  v35 = &v33->pConstructor;
  if ( v8 != v34 )
  {
    if ( v34 )
    {
      if ( ((unsigned __int8)v34 & 1) != 0 )
      {
        v35->pObject = (Scaleform::GFx::AS3::Class *)((char *)v34 - 1);
      }
      else
      {
        v36 = v34->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v36) != 0 )
        {
          v34->RefCount = v36 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
        }
      }
    }
    v35->pObject = v8;
  }
  v37 = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)vm->MHeap->Alloc(vm->MHeap, 120, 0);
  if ( v37 )
  {
    Scaleform::GFx::AS3::InstanceTraits::VTableInd::VTableInd(v37, vm);
    v39 = v38;
  }
  else
  {
    v39 = 0;
  }
  v40 = this->VTableTraits.pObject;
  if ( v39 != v40 )
  {
    if ( v40 )
    {
      if ( ((unsigned __int8)v40 & 1) != 0 )
      {
        this->VTableTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)((char *)v40 - 1);
      }
      else
      {
        v41 = v40->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v41) != 0 )
        {
          v40->RefCount = v41 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v40);
        }
      }
    }
    this->VTableTraits.pObject = v39;
  }
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v42 = this->VTableTraits.pObject;
  v43 = v42->pConstructor.pObject;
  v44 = &v42->pConstructor;
  if ( v8 != v43 )
  {
    if ( v43 )
    {
      if ( ((unsigned __int8)v43 & 1) != 0 )
      {
        v44->pObject = (Scaleform::GFx::AS3::Class *)((char *)v43 - 1);
        v44->pObject = v8;
        return;
      }
      v45 = v43->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v45) != 0 )
      {
        v43->RefCount = v45 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v43);
      }
    }
    v44->pObject = v8;
  }
}
