btConvexHullInternal::Point32 *__userpurge btConvexHullInternal::Point32::operator-@<eax>(
        btConvexHullInternal::Point32 *this@<ecx>,
        btConvexHullInternal::Point32 *a2@<eax>,
        btConvexHullInternal::Point32 *result,
        const btConvexHullInternal::Point32 *b)
{
  int v4; // edx

  a2->index = -1;
  a2->x = result->x - this->x;
  v4 = result->z - this->z;
  a2->y = result->y - this->y;
  a2->z = v4;
  return a2;
}
