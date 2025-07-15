void __userpurge Scaleform::GFx::AS3::Classes::fl::Date::Call(
        Scaleform::GFx::AS3::Classes::fl::Date *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  int localTZA; // [esp+1Ch] [ebp-8Ch] BYREF
  double timeValue; // [esp+20h] [ebp-88h] BYREF
  char out[128]; // [esp+28h] [ebp-80h] BYREF

  Scaleform::GFx::AS3::Instances::fl::Date::GetCurrentTimeValue(a2, &timeValue, &localTZA);
  v7 = Scaleform::GFx::AS3::Instances::fl::Date::formatDateTimeString(out, 0x80u, timeValue, localTZA, 1, 1, 0);
  localTZA = (int)Scaleform::GFx::ASStringManager::CreateStringNode(
                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                    (__m128i *)out,
                    v7);
  ++*(_DWORD *)(localTZA + 12);
  Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&localTZA);
  v8 = (Scaleform::GFx::ASStringNode *)localTZA;
  --*(_DWORD *)(localTZA + 12);
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
