void __thiscall Scaleform::GFx::AS3::Classes::fl_system::System::totalMemoryGet(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        unsigned int *result)
{
  *result = Scaleform::Memory::pGlobalHeap->GetTotalFootprint(Scaleform::Memory::pGlobalHeap);
}
