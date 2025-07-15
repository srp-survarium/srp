bool __thiscall Scaleform::GFx::AS2::Environment::NeedTermination(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::InteractiveObject *Target; // eax
  bool result; // al

  result = (execType == Exec_Unknown || execType == Exec_Event)
        && ((Target = this->Target,
             (Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0)
         || Target->Depth < -1)
        || (this->Target->Flags & 0x10) != 0;
  return result;
}
