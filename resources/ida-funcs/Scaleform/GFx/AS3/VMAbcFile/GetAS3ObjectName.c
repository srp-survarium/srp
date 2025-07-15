Scaleform::String *__thiscall Scaleform::GFx::AS3::VMAbcFile::GetAS3ObjectName(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::String *result)
{
  Scaleform::String::String(result, &this->File.pObject->Source);
  return result;
}
