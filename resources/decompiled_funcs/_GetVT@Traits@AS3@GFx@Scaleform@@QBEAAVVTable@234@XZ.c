Scaleform::GFx::AS3::VTable *__thiscall Scaleform::GFx::AS3::Traits::GetVT(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *p_pVTable; // ebp
  Scaleform::GFx::AS3::VTable *v3; // edi
  const Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::VTable *v5; // eax
  Scaleform::GFx::AS3::VTable *v7; // eax

  p_pVTable = &this->pVTable;
  if ( this->pVTable.pObject )
    return p_pVTable->pObject;
  if ( !this->pParent.pObject )
  {
    v7 = (Scaleform::GFx::AS3::VTable *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 16, 0);
    if ( v7 )
    {
      v7->pTraits = this;
      v7->VTMethods.Data.Data = 0;
      v7->VTMethods.Data.Size = 0;
      v7->VTMethods.Data.Policy.Capacity = 0;
      Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(p_pVTable, v7);
      return p_pVTable->pObject;
    }
    Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(p_pVTable, 0);
    return p_pVTable->pObject;
  }
  v3 = (Scaleform::GFx::AS3::VTable *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 16, 0);
  if ( v3 )
  {
    VT = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)this->pParent.pObject);
    Scaleform::GFx::AS3::VTable::VTable(v3, this, VT);
    Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(p_pVTable, v5);
  }
  else
  {
    Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::operator=(p_pVTable, 0);
  }
  return p_pVTable->pObject;
}
