#include <gtest/gtest.h>

#include <FSTLineSequencer.hpp>

#include <vector>
#include <utility>

/**
 * @brief Test fixture
 * Contains list of lines and corresponding sequences
 * 
 */
class LineSequencerTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        // lvl # 1-1 (5x5)
        // Rows
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 0, 1, 0},
                    {1, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 1},
                    {5}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 1},
                    {5}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 1, 1, 0},
                    {3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 0, 1, 0, 0},
                    {1}
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 1, 0, 0},
                    {2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 0},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 1, 1, 1},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 0},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 1, 0, 0},
                    {2}
                )
            );

        // lvl # 1-2 (10x10)
        // Rows
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 0, 0, 1, 0, 0, 1, 1, 1},
                    {2, 1, 3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    {1, 1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    {1, 1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                    {1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                    {2, 3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                    {3, 4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                    {4, 3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
                    {1, 5, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                    {1, 2, 2, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                    {1, 2, 1, 3}
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                    {8, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                    {1, 3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
                    {3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                    {1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                    {2, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
                    {2, 4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                    {1, 3, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                    {6, 1, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, NS::Sequence>(
                    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                    {7, 2}
                )
            );
    }

    std::vector<std::pair<ILineSequencer::Line, NS::Sequence>> testLinesSequences;
};

TEST_F(LineSequencerTest, FSTLineSequencer) {
    FSTLineSequencer sequencer;

    for(const auto& lineSequence : testLinesSequences) {
        EXPECT_EQ(sequencer(lineSequence.first), lineSequence.second);
    }
}