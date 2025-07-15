Scaleform::GFx::AS3::VTable *__thiscall Scaleform::GFx::AS3::Traits::GetVT(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::VTable *v2; // edi
  const Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::VTable *v4; // eax
  Scaleform::GFx::AS3::VTable *v5; // edi
  Scaleform::GFx::AS3::VTable *v6; // eax
  Scaleform::GFx::AS3::VTable *v7; // eax
  Scaleform::GFx::AS3::VTable *pObject; // ecx

  if ( this->pVTable.pObject )
    return this->pVTable.pObject;
  if ( !this->pParent.pObject )
  {
    v6 = (Scaleform::GFx::AS3::VTable *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 32, 0);
    if ( v6 )
    {
      Scaleform::GFx::AS3::VTable::VTable(v6, this);
      v5 = v7;
      goto LABEL_8;
    }
LABEL_7:
    v5 = 0;
    goto LABEL_8;
  }
  v2 = (Scaleform::GFx::AS3::VTable *)this->pVM->MHeap->Alloc(this->pVM->MHeap, 32, 0);
  if ( !v2 )
    goto LABEL_7;
  VT = Scaleform::GFx::AS3::Traits::GetVT(this->pParent.pObject);
  Scaleform::GFx::AS3::VTable::VTable(v2, this, VT);
  v5 = v4;
LABEL_8:
  pObject = this->pVTable.pObject;
  if ( pObject != v5 )
  {
    if ( pObject )
    {
      if ( this->pVTable.Owner )
      {
        this->pVTable.Owner = 0;
        Scaleform::GFx::AS3::VTable::`scalar deleting destructor'(pObject, 1);
      }
    }
    this->pVTable.pObject = v5;
  }
  this->pVTable.Owner = v5 != 0;
  return this->pVTable.pObject;
}
