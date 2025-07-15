void __thiscall Scaleform::GFx::AS3::Classes::fl_system::System::gc(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        const Scaleform::GFx::AS3::Value *result)
{
  this->pTraits.pObject->pVM->GC.GC->CollectionScheduledFlags = 40;
}
