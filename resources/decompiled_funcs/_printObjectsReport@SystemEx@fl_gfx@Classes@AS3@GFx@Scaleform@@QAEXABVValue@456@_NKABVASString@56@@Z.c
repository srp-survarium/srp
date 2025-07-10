void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::printObjectsReport(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        const Scaleform::GFx::AS3::Value *result,
        bool runGarbageCollector,
        unsigned int reportFlags,
        const Scaleform::GFx::ASString *swfFilter)
{
  void (__thiscall *v5)(Scaleform::GFx::AS3::VM *); // esi

  v5 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( runGarbageCollector )
    (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), int))(*(_DWORD *)v5 + 192))(v5, 2);
  (*(void (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), unsigned int, _DWORD, const char *))(*(_DWORD *)v5 + 204))(
    v5,
    reportFlags,
    0,
    swfFilter->pNode->pData);
}
