void __thiscall Scaleform::GFx::AS3::IntervalTimer::SetArguments(
        Scaleform::GFx::AS3::IntervalTimer *this,
        unsigned int num,
        Scaleform::GFx::AS3::Value *argArr)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Params; // edi
  unsigned int v5; // ebp
  unsigned int Size; // eax
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Value *Data; // eax
  unsigned int *p_Flags; // eax

  if ( num )
  {
    p_Params = &this->Params;
    v5 = num;
    do
    {
      Size = p_Params->Data.Size;
      v7 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v7 >= p_Params->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Params->Data,
            p_Params,
            v7 + (v7 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&p_Params->Data.Data[Size + 1], 0xFFFFFFFF);
        if ( v7 < p_Params->Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Params->Data,
            p_Params,
            v7);
      }
      Data = p_Params->Data.Data;
      p_Params->Data.Size = v7;
      p_Flags = &Data[v7 - 1].Flags;
      if ( p_Flags )
      {
        *p_Flags = argArr->Flags;
        p_Flags[1] = (unsigned int)argArr->Bonus.pWeakProxy;
        p_Flags[2] = argArr->value.VS._1.VUInt;
        p_Flags[3] = (unsigned int)argArr->value.VS._2.VObj;
        if ( (argArr->Flags & 0x1F) > 9 )
        {
          if ( (argArr->Flags & 0x200) != 0 )
            ++argArr->Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(argArr);
        }
      }
      ++argArr;
      --v5;
    }
    while ( v5 );
  }
}
