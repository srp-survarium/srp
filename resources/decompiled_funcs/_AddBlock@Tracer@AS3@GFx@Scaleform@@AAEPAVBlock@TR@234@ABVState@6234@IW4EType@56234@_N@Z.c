Scaleform::GFx::AS3::TR::Block *__thiscall Scaleform::GFx::AS3::Tracer::AddBlock(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::TR::State *st,
        unsigned int from,
        Scaleform::GFx::AS3::TR::Block::EType type,
        Scaleform::GFx::AS3::TR::State *checkOpCode)
{
  Scaleform::GFx::AS3::TR::Block *result; // eax
  Scaleform::GFx::AS3::TR::Block::EType v7; // ebx
  Scaleform::GFx::AS3::TR::Block *pPrev; // esi
  Scaleform::GFx::AS3::TR::State *v9; // eax
  Scaleform::GFx::AS3::TR::State *v10; // eax
  Scaleform::GFx::AS3::TR::State *v11; // ebp
  bool onlyCreateState; // [esp+9h] [ebp-1h]
  bool is_dead; // [esp+16h] [ebp+Ch]

  if ( from >= this->CodeEnd )
    return 0;
  v7 = type;
  pPrev = this->Blocks.Root.pPrev;
  for ( is_dead = type == tDead; pPrev; pPrev = pPrev->pPrev )
  {
    if ( from >= pPrev->From )
      break;
  }
  onlyCreateState = 0;
  if ( pPrev && from == pPrev->From )
  {
    if ( pPrev->State )
      return pPrev;
    onlyCreateState = 1;
  }
  if ( (_BYTE)checkOpCode && (this->pCode[from] == 9 || this->pCode[from] > 0xEEu && this->pCode[from] <= 0xF1u) )
    is_dead = 0;
  v9 = (Scaleform::GFx::AS3::TR::State *)this->Heap->Alloc(this->Heap, 68, 0);
  if ( v9 )
  {
    Scaleform::GFx::AS3::TR::State::State(v9, st);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  checkOpCode = v11;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
    &this->States,
    &checkOpCode);
  if ( v7 == tDead )
    v7 = is_dead;
  if ( onlyCreateState )
  {
    pPrev->Type |= v7;
    pPrev->State = v11;
    return pPrev;
  }
  else
  {
    result = (Scaleform::GFx::AS3::TR::Block *)this->Heap->Alloc(this->Heap, 24, 0);
    if ( result )
    {
      *((_DWORD *)result + 2) |= 1u;
      result->Type = v7;
      result->State = v11;
      result->From = from;
    }
    else
    {
      result = 0;
    }
    result->pPrev = pPrev->pNext->Scaleform::ListNode<Scaleform::GFx::AS3::TR::Block>::$8EB7788630741AFED8F7DC5F2C94762D::pPrev;
    result->pNext = pPrev->pNext;
    pPrev->pNext->Scaleform::ListNode<Scaleform::GFx::AS3::TR::Block>::$8EB7788630741AFED8F7DC5F2C94762D::pPrev = result;
    pPrev->pNext = result;
    if ( v7 == tDead )
      *((_DWORD *)result + 2) &= ~1u;
  }
  return result;
}
