void __thiscall Scaleform::GFx::AS3::VM::exec_typeof(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  int v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  int p_NullStringNode; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value other; // [esp+8h] [ebp-10h] BYREF

  pCurrent = this->OpStack.pCurrent;
  switch ( pCurrent->Flags & 0x1F )
  {
    case 0u:
      v3 = 1;
      break;
    case 1u:
      v3 = 6;
      break;
    case 2u:
    case 3u:
    case 4u:
      v3 = 7;
      break;
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      v3 = 9;
      break;
    case 0xAu:
      v3 = 2 * (pCurrent->value.VS._1.VInt == 0) + 8;
      break;
    case 0xBu:
    case 0xCu:
      v3 = (0xB00000001LL
          - (unsigned __int64)(unsigned int)(Scaleform::GFx::AS3::VM::GetValueTraits(this, this->OpStack.pCurrent)->TraitsType
                                           - 13)) >> 32;
      break;
    default:
      v3 = 12;
      break;
  }
  pNode = this->StringManagerRef->Builtins[v3].pNode;
  p_NullStringNode = (int)&pNode->pManager->NullStringNode;
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0;
  other.value.VS._1.VInt = (int)pNode;
  if ( pNode == (Scaleform::GFx::ASStringNode *)p_NullStringNode )
  {
    other.value.VS._1.VInt = 0;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)other.Bonus.pWeakProxy;
    other.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  Scaleform::GFx::AS3::Value::Assign(pCurrent, &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      pWeakProxy = other.Bonus.pWeakProxy;
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}
