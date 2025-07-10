bool __thiscall SpeedTree::SForestCullResults::Reserve(
        SpeedTree::SForestCullResults *this,
        const SpeedTree::CArray<SpeedTree::CCore *,1> *__formal,
        int nMaxNumBaseTrees,
        unsigned int nMaxNumVisibleCells,
        int nMaxVisibleInstancesPerBase,
        bool a6)
{
  bool v7; // bl
  bool v8; // bl

  v7 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
         (SpeedTree::CArray<SpeedTree::CCore *,1> *)&this->m_aVisibleCells,
         nMaxNumVisibleCells);
  v8 = SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
         (SpeedTree::CArray<SpeedTree::CCore *,1> *)&this->m_aNewVisibleCells,
         nMaxNumVisibleCells)
    && v7;
  return v8
       & SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
           (SpeedTree::CArray<SpeedTree::CCore *,1> *)&this->m_aPreviousVisibleCells,
           nMaxNumVisibleCells);
}
