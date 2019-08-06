#include <array>

using Array2d4 = std::array< std::array<char, 4>, 4>;

const Array2d4 I = {{{'-', 'I', '-', '-'},
					{'-', 'I', '-', '-'},
					{'-', 'I', '-', '-'},
					{'-', 'I', '-', '-'}}};

const Array2d4 T = {{{'-', 'T', '-', '-'},
					{'-', 'T', 'T', '-'},
					{'-', 'T', '-', '-'},
					{'-', '-', '-', '-'}}};

const Array2d4 J = {{{'-', '-', 'J', '-'},
					{'-', '-', 'J', '-'},
					{'-', 'J', 'J', '-'},
					{'-', '-', '-', '-'}}};

const Array2d4 L = {{{'-', 'L', '-', '-'},
					{'-', 'L', '-', '-'},
					{'-', 'L', 'L', '-'},
					{'-', '-', '-', '-'}}};

const Array2d4 O = {{{'-', '-', '-', '-'},
					{'-', 'O', 'O', '-'},
					{'-', 'O', 'O', '-'},
					{'-', '-', '-', '-'}}};

const Array2d4 Z = {{{'-', '-', '-', '-'},
					{'Z', 'Z', '-', '-'},
					{'-', 'Z', 'Z', '-'},
					{'-', '-', '-', '-'}}};

const Array2d4 S = {{{'-', '-', '-', '-'},
					{'-', 'S', 'S', '-'},
					{'S', 'S', '-', '-'},
					{'-', '-', '-', '-'}}};



const std::array<Array2d4, 7> tetrominos = {I, T, J, L, O, Z, S};
