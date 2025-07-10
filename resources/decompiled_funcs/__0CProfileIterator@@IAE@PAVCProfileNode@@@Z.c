CProfileIterator *__usercall CProfileIterator::CProfileIterator@<eax>(
        CProfileIterator *this@<ecx>,
        CProfileIterator *result@<eax>)
{
  result->CurrentParent = &CProfileManager::Root;
  result->CurrentChild = CProfileManager::Root.Child;
  return result;
}
