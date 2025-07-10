btBoxBoxDetector *__userpurge btBoxBoxDetector::btBoxBoxDetector@<eax>(
        btBoxBoxDetector *this@<ecx>,
        btBoxBoxDetector *result@<eax>,
        btBoxShape *box1,
        btBoxShape *box2)
{
  result->__vftable = (btBoxBoxDetector_vtbl *)&btBoxBoxDetector::`vftable';
  result->m_box1 = (btBoxShape *)this;
  result->m_box2 = box1;
  return result;
}
