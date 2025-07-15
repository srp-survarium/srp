char __thiscall Scaleform::GFx::AS2::ColorMatrixFilterObject::GetMember(
        Scaleform::GFx::AS2::ColorMatrixFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::MemoryHeap_vtbl *v7; // edx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS2::ArrayObject *v9; // eax
  Scaleform::GFx::AS2::ArrayObject *v10; // eax
  Scaleform::GFx::AS2::ArrayObject *v11; // edi
  int i; // esi
  unsigned int RefCount; // eax
  char result; // al
  const Scaleform::Render::BlurFilterParams *v17; // eax
  const Scaleform::Render::BlurFilterParams *v18; // eax
  const Scaleform::Render::BlurFilterParams *v19; // eax
  const Scaleform::Render::BlurFilterParams *v20; // eax
  const Scaleform::Render::BlurFilterParams *v21; // eax
  Scaleform::GFx::AS2::Value vala; // [esp+10h] [ebp-64h] BYREF
  _DWORD v23[20]; // [esp+24h] [ebp-50h]
  float penva; // [esp+78h] [ebp+4h]
  float penvb; // [esp+78h] [ebp+4h]
  float v26; // [esp+80h] [ebp+Ch]
  float v27; // [esp+80h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "matrix") )
  {
    pLocalFrame = this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame && pLocalFrame->RootIndex == 8 )
    {
      pHeap = penv->StringContext.pContext->pHeap;
      v7 = pHeap->__vftable;
      v23[10] = 8;
      Alloc = v7->Alloc;
      v23[0] = 0;
      v23[1] = 1;
      v23[2] = 2;
      v23[3] = 3;
      v23[4] = 16;
      v23[5] = 4;
      v23[6] = 5;
      v23[7] = 6;
      v23[8] = 7;
      v23[9] = 17;
      v23[11] = 9;
      v23[12] = 10;
      v23[13] = 11;
      v23[14] = 18;
      v23[15] = 12;
      v23[16] = 13;
      v23[17] = 14;
      v23[18] = 15;
      v23[19] = 19;
      v9 = (Scaleform::GFx::AS2::ArrayObject *)Alloc(pHeap, 80u, 0);
      if ( v9 )
      {
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v9, penv);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      Scaleform::GFx::AS2::ArrayObject::Resize(v11, 20);
      for ( i = 0; i < 20; ++i )
      {
        *(double *)((char *)&vala.NV.NumberValue + 4) = *((float *)&pLocalFrame->Variables.mHash.pTable + v23[i]);
        vala.V.BooleanValue = 3;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v11, i, (const Scaleform::GFx::AS2::Value *)&vala.NV.4);
        if ( vala.V.BooleanValue >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&vala.NV.4);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(val, v11);
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else if ( !strcmp(name->pNode->pData, "blurX") )
  {
    penva = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16))->BlurX;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    v26 = penva * 0.05000000074505806;
    val->NV.NumberValue = v26;
  }
  else if ( !strcmp(name->pNode->pData, "blurY") )
  {
    penvb = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16))->BlurY;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    result = 1;
    v27 = penvb * 0.05000000074505806;
    val->NV.NumberValue = v27;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "color") )
  {
    v17 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetInt(val, v17->Colors[0].Raw & 0xFFFFFF);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "inner") )
  {
    v18 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetBool(val, (v18->Mode & 0x20) != 0);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "knockout") )
  {
    v19 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetBool(val, (v19->Mode & 0x10) != 0);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "quality") )
  {
    v20 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetInt(val, v20->Passes);
    return 1;
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "strength") )
  {
    v21 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::ColorMatrixFilterObject *)((char *)this - 16));
    Scaleform::GFx::AS2::Value::SetNumber(val, v21->Strength);
    return 1;
  }
  else
  {
    return ((int (__thiscall *)(Scaleform::GFx::AS2::ColorMatrixFilterObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::ColorMatrixFilterObject)(
             this,
             &penv->StringContext,
             name,
             val);
  }
  return result;
}
