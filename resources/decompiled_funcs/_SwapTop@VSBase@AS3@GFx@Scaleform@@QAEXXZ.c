void __thiscall Scaleform::GFx::AS3::VSBase::SwapTop(Scaleform::GFx::AS3::VSBase *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::V2U v2; // edx
  Scaleform::GFx::AS3::Value::V1U v3; // ebx
  unsigned int Flags; // esi
  Scaleform::GFx::AS3::Value::Extra v5; // edi
  Scaleform::GFx::AS3::Value *v6; // edx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::Value *v8; // eax
  Scaleform::GFx::AS3::Value::V2U v9; // ecx
  Scaleform::GFx::AS3::Value _1; // [esp+10h] [ebp-10h] BYREF

  pCurrent = this->pCurrent;
  v2.VObj = (Scaleform::GFx::AS3::Object *)this->pCurrent->value.VS._2;
  v3 = this->pCurrent->value.VS._1;
  Flags = this->pCurrent->Flags;
  pCurrent->Flags = 0;
  v5.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pCurrent->Bonus;
  _1.value.VS._2 = v2;
  v6 = this->pCurrent;
  v7 = this->pCurrent[-1].Flags;
  _mm_prefetch((const char *)&this->pCurrent[-1], 2);
  v6->Flags = v7;
  v6->Bonus.pWeakProxy = v6[-1].Bonus.pWeakProxy;
  v6->value = *(Scaleform::GFx::AS3::Value::VU *)&v6[-1].value.VNumber;
  v6[-1].Flags = 0;
  v8 = this->pCurrent - 1;
  v8->Flags = Flags;
  v8->Bonus = v5;
  _1.Bonus = v5;
  _1.Flags = Flags;
  _1.value.VS._1 = v3;
  _mm_prefetch((const char *)&_1, 2);
  v9.VObj = (Scaleform::GFx::AS3::Object *)_1.value.VS._2;
  v8->value.VS._1 = v3;
  v8->value.VS._2 = v9;
}
