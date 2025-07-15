void __thiscall Scaleform::GFx::ASUserData::SetLastObjectValue(
        Scaleform::GFx::ASUserData *this,
        Scaleform::GFx::Value::ObjectInterface *pobjIfc,
        void *pdata,
        bool isdobj)
{
  this->pLastObjectInterface = pobjIfc;
  this->pLastData = pdata;
  this->IsLastDispObj = isdobj;
}
