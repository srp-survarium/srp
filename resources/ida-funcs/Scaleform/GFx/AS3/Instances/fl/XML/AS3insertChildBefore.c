void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3insertChildBefore(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *child1,
        const Scaleform::GFx::AS3::Value *child2)
{
  if ( this->InsertChildBefore(this, &child2, child1, child2)->Result )
  {
    Scaleform::GFx::AS3::Value::Assign(result, this);
    return;
  }
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      result->Flags &= 0xFFFFFFE0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags &= 0xFFFFFFE0;
}
