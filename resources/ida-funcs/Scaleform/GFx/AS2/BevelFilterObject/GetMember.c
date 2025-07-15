char __thiscall Scaleform::GFx::AS2::BevelFilterObject::GetMember(
        Scaleform::GFx::AS2::BevelFilterObject *this,
        float penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASString *v4; // ebx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  double v7; // st7
  Scaleform::GFx::AS2::Value *v8; // esi
  double v9; // st7
  char result; // al
  const Scaleform::Render::BlurFilterParams *v11; // eax
  Scaleform::GFx::AS2::Value *v12; // esi
  double v13; // st7
  const Scaleform::Render::BlurFilterParams *v14; // eax
  Scaleform::GFx::AS2::LocalFrame *v15; // eax
  double v16; // st7
  double Alpha; // st7
  const Scaleform::Render::BlurFilterParams *v18; // eax
  const Scaleform::Render::BlurFilterParams *v19; // eax
  const Scaleform::Render::BlurFilterParams *v20; // eax
  const Scaleform::Render::BlurFilterParams *v21; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *v23; // ecx

  v4 = name;
  if ( !strcmp(name->pNode->pData, "angle") )
  {
    pLocalFrame = this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame && pLocalFrame->RootIndex <= 5 )
      v7 = *(float *)&pLocalFrame->Caller.T.Type;
    else
      v7 = 0.0;
    v8 = val;
    penv = v7;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    v9 = penv;
    v8->T.Type = 4;
    v8->NV.Int32Value = (int)v9;
    return 1;
  }
  if ( !strcmp(name->pNode->pData, "blurX") )
  {
    v11 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    v12 = val;
    penv = v11->BlurX;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
LABEL_12:
    v13 = penv * 0.05000000074505806;
    v12->T.Type = 3;
    result = 1;
    *(float *)&val = v13;
    v12->NV.NumberValue = *(float *)&val;
    return result;
  }
  if ( !strcmp(name->pNode->pData, "blurY") )
  {
    v14 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    v12 = val;
    penv = v14->BlurY;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    goto LABEL_12;
  }
  if ( !Scaleform::GFx::ASString::operator==(name, "distance") )
  {
    if ( Scaleform::GFx::ASString::operator==(v4, "highlightAlpha") )
    {
      Alpha = Scaleform::GFx::AS2::BitmapFilterObject::GetAlpha((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
    }
    else
    {
      if ( Scaleform::GFx::ASString::operator==(v4, "highlightColor") )
      {
        v18 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
        Scaleform::GFx::AS2::Value::SetInt(val, v18->Colors[0].Raw & 0xFFFFFF);
        return 1;
      }
      if ( Scaleform::GFx::ASString::operator==(v4, "shadowAlpha") )
      {
        Alpha = Scaleform::GFx::AS2::BitmapFilterObject::GetAlpha2((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
      }
      else
      {
        if ( Scaleform::GFx::ASString::operator==(v4, "shadowColor") )
        {
          v19 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetInt(val, v19->Colors[1].Raw & 0xFFFFFF);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(v4, "knockout") )
        {
          v20 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetBool(val, (v20->Mode & 0x10) != 0);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(v4, "quality") )
        {
          v21 = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16));
          Scaleform::GFx::AS2::Value::SetInt(val, v21->Passes);
          return 1;
        }
        if ( Scaleform::GFx::ASString::operator==(v4, "type") )
        {
          if ( (Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16))->Mode
              & 0x20) != 0 )
            StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                           *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(penv) + 116)
                                                                                       + 20)
                                                                           + 12)
                                                               + 788),
                           (__m128i *)"inner");
          else
            StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                           *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(LODWORD(penv) + 116)
                                                                                       + 20)
                                                                           + 12)
                                                               + 788),
                           (__m128i *)"outer");
          v23 = val;
          ++StringNode->RefCount;
          penv = *(float *)&StringNode;
          Scaleform::GFx::AS2::Value::SetString(v23, (const Scaleform::GFx::ASString *)&penv);
          if ( StringNode->RefCount-- == 1 )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
            return 1;
          }
          return 1;
        }
        if ( !Scaleform::GFx::ASString::operator==(v4, "strength") )
          return ((int (__thiscall *)(Scaleform::GFx::AS2::BevelFilterObject *, int, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::BevelFilterObject)(
                   this,
                   LODWORD(penv) + 116,
                   v4,
                   val);
        penv = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BevelFilterObject *)((char *)this - 16))->Strength;
        Alpha = penv;
      }
    }
    Scaleform::GFx::AS2::Value::SetNumber(val, Alpha);
    return 1;
  }
  v15 = this->ResolveHandler.pLocalFrame;
  if ( v15 && v15->RootIndex <= 5 )
    v16 = *((float *)&v15->Callee.NV + 3);
  else
    v16 = 0.0;
  penv = v16;
  Scaleform::GFx::AS2::Value::SetInt(val, (int)penv);
  return 1;
}
