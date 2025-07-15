void __thiscall Scaleform::GFx::AS3::TR::State::FindProp(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::PropRef *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *mn,
        Scaleform::GFx::AS3::TR::State::ScopeType *stype,
        unsigned int *scope_index)
{
  const Scaleform::GFx::AS3::Multiname *v5; // ebp
  Scaleform::GFx::AS3::Abc::MultinameKind Data; // eax
  char v7; // dl
  Scaleform::GFx::AS3::VM *VMRef; // ebx
  unsigned int Size; // eax
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v10; // edx
  unsigned int v11; // edi
  Scaleform::GFx::AS3::Value *v12; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  const Scaleform::GFx::AS3::Traits *v14; // ebp
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // edx
  unsigned int v17; // eax
  int v18; // ebp
  const Scaleform::GFx::AS3::PropRef *v19; // eax
  unsigned int v20; // edi
  Scaleform::GFx::AS3::Value *v21; // esi
  const Scaleform::GFx::AS3::Traits *v22; // eax
  const Scaleform::GFx::AS3::SlotInfo *v23; // eax
  int v24; // eax
  Scaleform::GFx::ASString *ClassTraits; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v26; // edi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *pNode; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  unsigned int v29; // ebp
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // edi
  void *v32; // eax
  const Scaleform::GFx::AS3::SlotInfo *v34; // eax
  const Scaleform::GFx::AS3::Multiname *v35; // edx
  unsigned int v36; // [esp-10h] [ebp-3Ch]
  unsigned int slot_index; // [esp+4h] [ebp-28h] BYREF
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *i; // [esp+8h] [ebp-24h]
  Scaleform::GFx::AS3::TR::State *v39; // [esp+Ch] [ebp-20h]
  const Scaleform::GFx::AS3::SlotInfo *v40; // [esp+10h] [ebp-1Ch]
  Scaleform::GFx::AS3::PropRef v41; // [esp+14h] [ebp-18h] BYREF

  v5 = (const Scaleform::GFx::AS3::Multiname *)mn;
  Data = (Scaleform::GFx::AS3::Abc::MultinameKind)mn->Data.Data;
  v7 = (int)mn->Data.Data & 3;
  v39 = this;
  if ( v7 != 1 && (Data & 4) == 0 )
  {
    VMRef = this->pTracer->CF->pFile->VMRef;
    Size = this->ScopeStack.Data.Size;
    slot_index = 0;
    if ( Size )
    {
      v10 = (const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(16 * Size - 16);
      for ( i = v10; ; v10 = i )
      {
        v11 = Size - 1;
        *scope_index = Size - 1;
        v12 = (Scaleform::GFx::AS3::Value *)((char *)v10 + (unsigned int)this->ScopeStack.Data.Data);
        ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, v12);
        v14 = ValueTraits;
        if ( (v12->Flags & 0x100) != 0 )
          break;
        if ( ValueTraits )
        {
          if ( !ValueTraits->IsGlobal(ValueTraits) )
          {
            FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                          (const Scaleform::GFx::AS3::SlotInfo *)VMRef,
                          v14,
                          mn,
                          &slot_index,
                          0);
            if ( FixedSlot )
            {
              v36 = slot_index;
              *stype = stScopeStack;
              Scaleform::GFx::AS3::PropRef::PropRef(&v41, v12, FixedSlot, v36);
              Scaleform::GFx::AS3::PropRef::operator=(result, v19);
              Scaleform::GFx::AS3::PropRef::~PropRef(&v41);
              return;
            }
          }
        }
        --i;
        this = v39;
        Size = v11;
        if ( !v11 )
        {
          v5 = (const Scaleform::GFx::AS3::Multiname *)mn;
          goto LABEL_12;
        }
      }
    }
    else
    {
LABEL_12:
      pSavedScope = this->pTracer->CF->pSavedScope;
      v17 = pSavedScope->Data.Size;
      i = pSavedScope;
      if ( v17 )
      {
        v18 = 16 * v17 - 16;
        while ( 1 )
        {
          v20 = v17 - 1;
          *scope_index = v17 - 1;
          v21 = (Scaleform::GFx::AS3::Value *)((char *)pSavedScope->Data.Data + v18);
          v22 = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v21);
          if ( (v21->Flags & 0x100) != 0 )
            break;
          v23 = Scaleform::GFx::AS3::FindFixedSlot(
                  (const Scaleform::GFx::AS3::SlotInfo *)VMRef,
                  v22,
                  mn,
                  &slot_index,
                  0);
          v40 = v23;
          if ( v23 )
          {
            v29 = slot_index;
            *stype = stStoredScope;
            Flags = v21->Flags;
            pWeakProxy = v21->Bonus.pWeakProxy;
            v41.This.value.VNumber = v21->value.VNumber;
            v41.pSI = v23;
            v41.SlotIndex = v29;
            v41.This.Flags = Flags;
            v41.This.Bonus.pWeakProxy = pWeakProxy;
            if ( (Flags & 0x1F) > 9 )
            {
              if ( (Flags & 0x200) != 0 )
              {
                ++pWeakProxy->RefCount;
              }
              else
              {
                Scaleform::GFx::AS3::Value::AddRefInternal(v21);
                v23 = v40;
              }
            }
            result->pSI = v23;
            result->SlotIndex = v29;
            Scaleform::GFx::AS3::Value::Assign(&result->This, &v41.This);
            if ( (v41.This.Flags & 0x1F) > 9 )
            {
              if ( (v41.This.Flags & 0x200) != 0 )
              {
                v32 = v41.This.Bonus.pWeakProxy;
                if ( v41.This.Bonus.pWeakProxy->RefCount-- == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v32);
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v41.This);
              }
            }
            return;
          }
          v17 = v20;
          v18 -= 16;
          if ( !v20 )
          {
            v5 = (const Scaleform::GFx::AS3::Multiname *)mn;
            this = v39;
            goto LABEL_20;
          }
          pSavedScope = i;
        }
      }
      else
      {
LABEL_20:
        v24 = v5->Name.Flags & 0x1F;
        if ( v24 != 8 && v24 != 9 )
        {
          ClassTraits = Scaleform::GFx::AS3::FindClassTraits(
                          VMRef,
                          v5,
                          (Scaleform::GFx::ASStringNode *)this->pTracer->CF->pFile->AppDomain);
          v26 = (const Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits;
          if ( ClassTraits
            && (pNode = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)ClassTraits[25].pNode) != 0
            && ((pNode->Flags & 0x10) == 0
              ? (pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)VMRef->GlobalObject.pObject)
              : (pObject = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetScript(pNode)),
                mn = 0,
                (v34 = Scaleform::GFx::AS3::FindFixedSlot(
                         (const Scaleform::GFx::AS3::SlotInfo *)VMRef,
                         pObject->pTraits.pObject,
                         (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)v5,
                         (unsigned int *)&mn,
                         pObject)) != 0) )
          {
            v35 = (const Scaleform::GFx::AS3::Multiname *)mn;
            pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
            result->SlotIndex = (unsigned int)v35;
            v41.SlotIndex = (unsigned int)v35;
            result->pSI = v34;
            v41.pSI = v34;
            v41.This.Flags = 12;
            v41.This.Bonus.pWeakProxy = 0;
            v41.This.value.VS._1.VInt = (int)pObject;
            Scaleform::GFx::AS3::Value::Assign(&result->This, &v41.This);
            Scaleform::GFx::AS3::PropRef::~PropRef(&v41);
            *stype = stGlobalObject;
          }
          else
          {
            Scaleform::GFx::AS3::FindGOProperty(
              result,
              VMRef,
              &VMRef->GlobalObjects,
              (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)v5,
              v26);
            if ( (result->This.Flags & 0x1F) != 0
              && (((int)result->pSI & 1) == 0 || ((int)result->pSI & 0xFFFFFFFE) != 0)
              && (((int)result->pSI & 2) == 0 || ((int)result->pSI & 0xFFFFFFFD) != 0) )
            {
              *stype = stGlobalObject;
            }
          }
        }
      }
    }
  }
}
