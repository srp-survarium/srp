void __thiscall survarium::flash_movie::CreateObject(
        survarium::flash_movie *this,
        survarium::flash_value *value,
        Scaleform::GFx::Value *pvalue)
{
  Scaleform::GFx::Movie::CreateObject(*(Scaleform::GFx::Movie **)&value->body[4], pvalue, 0, 0, 0);
}
