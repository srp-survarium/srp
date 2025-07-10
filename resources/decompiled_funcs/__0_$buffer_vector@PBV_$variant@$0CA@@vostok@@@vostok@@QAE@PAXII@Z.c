void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<ecx>,
        vostok::buffer_vector<vostok::variant<32> const *> **a2@<eax>,
        unsigned int buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  *a2 = this;
  a2[1] = (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)this + 4 * buffer);
}
