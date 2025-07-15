char __thiscall Scaleform::GFx::AS2::ColorTransformObject::GetMember(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  long double v5; // st7
  double v7; // st7
  double v8; // st7
  unsigned __int8 v9; // bl
  double v10; // st7
  Scaleform::GFx::AS2::Value v; // [esp+18h] [ebp-10h] BYREF
  float penva; // [esp+2Ch] [ebp+4h]
  float penvb; // [esp+2Ch] [ebp+4h]
  float rca; // [esp+30h] [ebp+8h]
  unsigned __int8 rc; // [esp+30h] [ebp+8h]

  if ( !strcmp(name->pNode->pData, "redMultiplier") )
  {
    v5 = *(float *)&this->ArePropertiesSet;
LABEL_3:
    v.T.Type = 3;
    goto LABEL_4;
  }
  if ( !strcmp(name->pNode->pData, "greenMultiplier") )
  {
    v5 = *((float *)&this->Scaleform::GFx::AS2::Object + 13);
    goto LABEL_3;
  }
  if ( !strcmp(name->pNode->pData, "blueMultiplier") )
  {
    v5 = *((float *)&this->Scaleform::GFx::AS2::Object + 14);
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "alphaMultiplier") )
  {
    v5 = *((float *)&this->Scaleform::GFx::AS2::Object + 15);
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "redOffset") )
  {
    v5 = this->mColorTransform.M[0][0];
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "greenOffset") )
  {
    v5 = this->mColorTransform.M[0][1];
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "blueOffset") )
  {
    v5 = this->mColorTransform.M[0][2];
    goto LABEL_3;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "alphaOffset") )
  {
    v5 = this->mColorTransform.M[0][3];
    goto LABEL_3;
  }
  if ( !Scaleform::GFx::ASString::operator==(name, "rgb") )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::ColorTransformObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::ColorTransformObject)(
             this,
             &penv->StringContext,
             name,
             val);
  if ( Scaleform::GFx::NumberUtil::IsNaN(this->mColorTransform.M[0][0]) )
    v7 = 0.0;
  else
    v7 = this->mColorTransform.M[0][0];
  rca = v7;
  rc = (int)rca;
  if ( Scaleform::GFx::NumberUtil::IsNaN(this->mColorTransform.M[0][1]) )
    v8 = 0.0;
  else
    v8 = this->mColorTransform.M[0][1];
  penva = v8;
  v9 = (int)penva;
  if ( Scaleform::GFx::NumberUtil::IsNaN(this->mColorTransform.M[0][2]) )
    v10 = 0.0;
  else
    v10 = this->mColorTransform.M[0][2];
  penvb = v10;
  v.T.Type = 3;
  v5 = (double)((unsigned __int8)(int)penvb | ((v9 | (rc << 8)) << 8));
LABEL_4:
  v.NV.NumberValue = v5;
  Scaleform::GFx::AS2::Value::operator=(val, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}
