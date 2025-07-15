int __thiscall Scaleform::StatsUpdate::SummaryStatIdVisitor::GetStatIdMemory(
        Scaleform::StatsUpdate::SummaryStatIdVisitor *this,
        Scaleform::StatDesc::Iterator it)
{
  int v3; // ebp
  Scaleform::StatDesc *i; // esi
  Scaleform::StatInfo v6; // [esp+10h] [ebp-1Ch] BYREF
  _DWORD v7[2]; // [esp+1Ch] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-8h]

  memset(&v6, 0, sizeof(v6));
  v3 = 0;
  if ( Scaleform::StatBag::GetStat(&this->StatIdBag, &v6, it.pDesc->Id) )
  {
    v7[0] = 0;
    v7[1] = uri;
    v8 = 0;
    v6.pInterface->GetStat(v6.pInterface, v6.pData, (Scaleform::Stat::StatValue *)v7, 0);
    v3 = v8;
  }
  for ( i = it.pDesc->pChild; i; i = i->pNextSibling )
    Scaleform::StatsUpdate::SummaryStatIdVisitor::GetStatIdMemory(this, (Scaleform::StatDesc::Iterator)i);
  return v3;
}
