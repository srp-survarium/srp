btDbvtAabbMm *__fastcall btDbvtAabbMm::FromMM(const btVector3 *mx, const btVector3 *mi, btDbvtAabbMm *a3)
{
  btDbvtAabbMm *result; // eax

  result = a3;
  a3->mi = (btVector3)mi->mVec128;
  a3->mx = (btVector3)mx->mVec128;
  return result;
}
