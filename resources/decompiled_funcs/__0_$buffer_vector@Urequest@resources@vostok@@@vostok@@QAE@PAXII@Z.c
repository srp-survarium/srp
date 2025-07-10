void __userpurge vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
        vostok::buffer_vector<vostok::resources::request> *this@<ecx>,
        vostok::buffer_vector<vostok::resources::request> **a2@<eax>,
        unsigned int buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  *a2 = this;
  a2[1] = &this[buffer];
}
