void __userpurge vostok::buffer_vector<vostok::tasks::thread_tls>::resize(
        vostok::buffer_vector<vostok::tasks::thread_tls> *this@<ecx>,
        int *a2@<esi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // eax

  v3 = *a2;
  v4 = size;
  v5 = a2[1] - *a2;
  v6 = v5 / 360;
  if ( size != v5 / 360 )
  {
    if ( size >= v5 / 360 )
    {
      size = 360 * size + v3;
      vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        (vostok::tasks::thread_tls *)(v3 + 360 * v6),
        (vostok::tasks::thread_tls *const *)&size);
    }
    else
    {
      size = v3 + 360 * v6;
      vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        (vostok::tasks::thread_tls *)(360 * v4 + v3),
        (vostok::tasks::thread_tls *const *)&size);
    }
    a2[1] = 360 * v4 + *a2;
  }
}
