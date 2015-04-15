/* The MIT License

   Copyright (c) 2015 Adrian Tan <atks@umich.edu>

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include "motif_tree.h"

#define A 1
#define C 2
#define G 4
#define T 8
#define N 15

/**
 * Constructor.
 */
MotifTree::MotifTree(uint32_t size)
{   
    mm = new MotifMap(size); 


    exit(1);

    std::cerr << "\tsize : " << size << "\n";
    std::cerr << "\t1<<2 : " << (1<<2) << "\n";
    std::cerr << "\t1<<4 : " << (1<<4) << "\n";
    std::cerr << "\t1<<6 : " << (1<<6) << "\n";
    std::cerr << "\t1<<8 : " << (1<<8) << "\n";
    std::cerr << "\t1<<10 : " << (1<<10) << "\n";
    std::cerr << "\t1<<12 : " << (1<<12) << "\n";
    std::cerr << "\t1<<14 : " << (1<<14) << "\n";
    std::cerr << "\t1<<16 : " << (1<<16) << "\n";
    std::cerr << "\tmax int16_t : " << 0xFFFF << "\n";

    tree = (node *) malloc(sizeof(node)*size);


    uint64_t value = 0;
    //you only want to loop through multiples of 2
//    for (uint32_t i=0; i<size; ++i)
//    {
//        uint32_t c = canonical(i);
//        tree[i] = ((uint64_t) c)<<32;
//        std::cerr << i << ":" << c << ":" << tree[i] << "\n";
//        if (i==1) exit(1);
//    }

    //enumerate size

    //map index to sequence


    //map sequence to index - 4 based

    uint32_t next_len_index;
    uint32_t clen = 1;
    uint32_t seq = 0;

exit(1);

    for (uint32_t i=0; i<size; ++i)
    {
        //node tnode = tree[i];
        if (i==next_len_index)
        {
            ++clen;
        }

        //for the len - extract base
        uint32_t c = canonical(seq);


    }

};

/**
 * Destructor.
 */
MotifTree::~MotifTree()
{
    if (tree) delete tree; 
    if (mm) delete mm;
};

/**
 * Construct suffix tree based on sequence.
 */
void MotifTree::set_sequence(char* sequence)
{
    //translate sequence to binary form
    uint32_t len = strlen(sequence);



};

/**
 * Construct suffix tree based on sequence up to max_motif_len.
 */
void MotifTree::set_sequence(char* sequence, int32_t max_motif_len)
{

};

/**
 * Gets candidate motifs up to max_motif_len.
 */
void MotifTree::get_candidate_motifs(std::vector<CandidateMotif>& candidate_motifs)
{

};

/**
 * Get canonical representation.
 */
uint32_t MotifTree::canonical(uint32_t motif)
{
    uint32_t cmotif = motif;
    uint32_t smotif = motif;
    std::cerr << "\t" << 0 << ") " << smotif << " - ";
    print(smotif);
    std::cerr << "\n";
    for (uint32_t i=1; i<8; ++i)
    {
        smotif = shift1(smotif);
        std::cerr << "\t" << i << ") " << smotif << " - ";
        print(smotif);
        std::cerr << "\n";
        cmotif = smotif<cmotif ? smotif : cmotif;
    }

    return cmotif;
}

/**
 * Converts index to sequence.
 */
uint32_t MotifTree::index2sequence(uint32_t index)
{
    return 0;
}

/**
 * Converts sequence to index.
 */
uint32_t sequence2index(uint32_t index)
{
    return 0;
}

/**
 * Gets index of child.
 */
uint32_t MotifTree::get_first_child(uint32_t index)
{
    return 0;
}

/**
 * Adds a suffix of sequence from start to end.
 */
void MotifTree::add_suffix(char* sequence, int32_t start, int32_t end)
{

};

/**
 * Converts base to index.
 */
int32_t MotifTree::base2index(char base)
{
    switch (base)
    {
        case 'A':
            return A;
            break;
        case 'C':
            return C;
            break;
        case 'G':
            return G;
            break;
        case 'T':
            return T;
            break;
        default:
            return N;
    }
};

/**
 * Print sequence.
 */
void MotifTree::print(uint32_t seq)
{
    uint8_t *seq_ptr = (uint8_t*) &seq;

    std::cerr << index2base(seq_ptr[0] & 0xF);
    std::cerr << index2base(seq_ptr[0] >> 4 & 0xF);
    std::cerr << index2base(seq_ptr[1] & 0xF);
    std::cerr << index2base(seq_ptr[1] >> 4 & 0xF);
    std::cerr << index2base(seq_ptr[2] & 0xF);
    std::cerr << index2base(seq_ptr[2] >> 4 & 0xF);
    std::cerr << index2base(seq_ptr[3] & 0xF);
    std::cerr << index2base(seq_ptr[3] >> 4 & 0xF);

//    for (uint32_t i=0; i<8; ++i)
//    {
//        //seqi(s, i) ((s)[(i)>>1] >> ((~(i)&1)<<2) & 0xf)
//        std::cerr << "(" << seqi(seq_ptr, i) << ")" ;
//        std::cerr << index2base(seqi(seq_ptr, i));
//    }
}

#undef A
#undef C
#undef G
#undef T
#undef N
