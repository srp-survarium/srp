Scaleform::String *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::GetAS3ObjectName(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this,
        Scaleform::String *result)
{
  Scaleform::String::String(
    result,
    (const Scaleform::String *)(*(_DWORD *)(this->pTraits.pObject[1].FirstOwnSlotNum + 60) + 12));
  return result;
}
