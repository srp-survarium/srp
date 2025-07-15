char __thiscall Scaleform::GFx::AS2::BlurFilterObject::GetMember(
        Scaleform::GFx::AS2::BlurFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // esi
  char result; // al
  unsigned int Passes; // edi
  float BlurX; // [esp+14h] [ebp+8h]
  float v8; // [esp+18h] [ebp+Ch]

  if ( !strcmp(name->pNode->pData, "blurX") )
  {
    v4 = val;
    BlurX = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurX;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
LABEL_4:
    v4->T.Type = 3;
    result = 1;
    v8 = BlurX * 0.05000000074505806;
    v4->NV.NumberValue = v8;
    return result;
  }
  if ( !strcmp(name->pNode->pData, "blurY") )
  {
    v4 = val;
    BlurX = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->BlurY;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    goto LABEL_4;
  }
  if ( strcmp(name->pNode->pData, "quality") )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::BlurFilterObject *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::BlurFilterObject)(
             this,
             &penv->StringContext,
             name,
             val);
  Passes = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams((Scaleform::GFx::AS2::BlurFilterObject *)((char *)this - 16))->Passes;
  if ( val->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(val);
  val->NV.Int32Value = Passes;
  val->T.Type = 4;
  return 1;
}
