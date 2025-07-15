unsigned int __thiscall Scaleform::GFx::AS3::ASRefCountCollector::CheckGenerations(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        bool *upgradeGen)
{
  unsigned int RunsCnt; // esi
  unsigned int v3; // edi
  unsigned int result; // eax

  *upgradeGen = 0;
  RunsCnt = this->RunsCnt;
  if ( !RunsCnt )
    return 0;
  if ( RunsCnt % this->RunsToCollectOld )
    v3 = RunsCnt % this->RunsToCollectYoung == 0;
  else
    v3 = 2;
  result = v3;
  if ( !(RunsCnt % this->RunsToUpgradeGen) )
    *upgradeGen = 1;
  return result;
}
